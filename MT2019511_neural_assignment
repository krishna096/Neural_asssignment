 AREA     appcode, CODE, READONLY
	 IMPORT printMsg_and
	 IMPORT printMsg_or
     IMPORT printMsg_nand
     IMPORT printMsg_nor
     IMPORT printMsg_xnor
     IMPORT printMsg_xor
     IMPORT printMsg_not
     IMPORT printSigmoid
     EXPORT __main
	 ENTRY 
__main  FUNCTION

                   
				   mov r12,#4 ; this register is used to select four datasets
				   mov r3, #7 ; reg for logic gate selection
;;;; logic weights and bias
logic_and          BL printMsg_and
				   VLDR.F32 s31 ,=-0.1 	;w0
		           VLDR.F32 s30 ,=0.2    ;w1   
                   VLDR.F32	s29 ,=0.2 	;w2
                   VLDR.F32 s28 ,=-0.2;  bias  
				   SUB R3,R3,#1 ; decrementing to select next logic gate
				   B data_sel  ; branching to datasets
				   
logic_or           BL printMsg_or
				   VLDR.F32 s31 ,=0.2 	;w0
		           VLDR.F32 s30 ,=0.2  ;w1   
                   VLDR.F32	s29 ,=0.2	;w2
                   VLDR.F32 s28 ,=-0.1;  bias  
				   SUB R3,R3,#1 ; decrementing to select next logic gate
				   B data_sel  ; branching to datasets
				   
logic_not          BL printMsg_not
				   VLDR.F32 s31 ,=-0.5 	;w0
		           VLDR.F32 s30 ,=-0.7    ;w1   
                   VLDR.F32	s29 ,=0.0 	;w2
                   VLDR.F32 s28 ,=0.1;  bias 
				   SUB R3,R3,#1 ;decrementing to select next logic gate
				   B data_sel ;; branching to datasets
				   
				   
logic_xor         BL printMsg_xor
				  VLDR.F32 s31 ,=-5.0 	;w0
		           VLDR.F32 s30 ,=20.0    ;w1   
                   VLDR.F32	s29 ,=10.0 	;w2
                   VLDR.F32 s28 ,=1.0 ;  bias
					SUB R3,R3,#1 ; decrementing to select next logic gate
					B data_sel  ;; branching to datasets
			
logic_xnor        BL printMsg_xnor
					VLDR.F32 s31 ,=-5.0 	;w0
		           VLDR.F32 s30 ,=20.0    ;w1   
                   VLDR.F32	s29 ,=10.0	;w2
                   VLDR.F32 s28 ,=1.0;  bias
                   SUB R3,R3,#1 ; decrementing to select next logic gate
				   B data_sel  ; ; branching to datasets

logic_nand         BL printMsg_nand
					VLDR.F32 s31 ,=0.6 	;w0
		           VLDR.F32 s30 ,=-0.8    ;w1   
                   VLDR.F32	s29 ,=-0.8	;w2
                   VLDR.F32 s28 ,=0.3;  bias  
				   SUB R3,R3,#1 ; decrementing to select next logic gate
				   B data_sel  ;; branching to datasets
				   
logic_nor         BL printMsg_nor
					VLDR.F32 s31 ,=0.2 	;w0
		           VLDR.F32 s30 ,=0.2    ;w1   
                   VLDR.F32	s29 ,=0.2	;w2
                   VLDR.F32 s28 ,=-0.7;  bias 
					SUB R3,R3,#1 ; decrementing to select next logic gate
					B data_sel   ; branching to datasets
                   				  

;;;;;;;;; selecting datasets ;;;;;;;;;;;
data_sel cmp R12, #4 
         beq set1

         cmp R12, #3
         beq set2

		cmp r12, #2
		beq set3

		cmp r12, #1
		beq set4 

;;;;;;;;;;;;;;;datasets ;;;;;;;;;;;;;;;;;

set1    VLDR.F32 s25 , =1 ;x0
        VLDR.F32 s26 , =0 ;x1
        VLDR.F32 s27 , =0 ;x2
		B z_calc ; branching to calculate W0.X0 + W1.X1 + W2.X2 + BIAS = Z

set2    VLDR.F32 s25 , =1 ;x0
        VLDR.F32 s26 , =0 ;x1
        VLDR.F32 s27 , =1 ;x2	
		B z_calc ; branching to calculate W0.X0 + W1.X1 + W2.X2 + BIAS = Z

set3    VLDR.F32 s25 , =1 ;x0
        VLDR.F32 s26 , =1 ;x1
        VLDR.F32 s27 , =0 ;x2	
		B z_calc ; branching to calculate W0.X0 + W1.X1 + W2.X2 + BIAS = Z

set4    VLDR.F32 s25 , =1 ;x0
        VLDR.F32 s26 , =1 ;x1
        VLDR.F32 s27 , =1 ;x2	
		B z_calc ; branching to calculate W0.X0 + W1.X1 + W2.X2 + BIAS = Z


;;;;;;;;;;;; z = w0x0+w1x1+w2x2+bias ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
z_calc  	VMUL.F32 S24,S31,S25 ; W0.X0
			VMUL.F32 S23,S30,S26 ; W1.X1
			VMUL.F32 S22,S29,S27 ; W2.X2
			VADD.F32 S21,S24,S23 ; W0.X0 + W1.X1
			VADD.F32 S20,S21,S22 ; W0.X0 + W1.X1 + W2.X2
			VADD.F32 S19,S20,S28 ; W0.X0 + W1.X1 + W2.X2 + BIAS = Z
			B sigmoid_fun ; branching to calculate 1/(1 + e^(-x) 
			
sigmoid_fun	MOV R5, #1 ; power of X
	        
	
	;;;;;;; input z to the sigmoid will be s19;;;;;;;;;;;;;;;;;;
	VNEG.F32 S1,S19 ; changing x to -x
	
	VLDR.F32 S3, = 1 
	VLDR.F32 S5, = 1 ; THIS FP REG S5 WILL DISPLAY THE RESULT of e^-x
	MOV R9, #25; Number of iterations
	;;; EXP SERIES EDITION;;;
	MOV R7, #1 ; temp reg to calculate factorial
mult_	  VMUL.F32 S3,S3,S1 ; z=z*x

FACTORIAL  MUL R7,R7,R5 ; calculating factorial for denominator
		   
		   
          vmov S0,R7 
          VCVT.F32.u32 S0,S0 ; converting s0 to Floating point 
	      VDIV.F32 S4,S3,S0 ; dividing by factorial 
		  VADD.F32 S5,S5,S4 ;  adding to the result ( result of e^(-x) ) 
		  
iter ADD R5,R5, #1 ; incrmenting power of x
	 SUB R9,R9, #1 ; decrementing iterations number
	 CMP R9, #0 
	 BNE mult_
	
SIGMOID VLDR.F32 S2, =1 ; NUMERATOR OF SIGMOID 
        VADD.F32 S6,S5,S2 ; calculating 1+e^(-x)
		VDIV.F32 S7,S2,S6 ; calculating 1/ 1+e^(-x)

		VLDR.F32 S17, = 0.5 ; setting threshold for logic output 

	    VCMP.F32 S7,S17 ; compating output with threshold
		
		VMRS APSR_nzcv, FPSCR
		MOVLE R0, #0
		MOVGT R0, #1
		;MOV R0, R6
	    BL printSigmoid ; printing outputs of logic gates
		sub r12, r12, #1 ; decrementing dataset register 
		cmp r12,#0
		BEQ logic_sel
	    B data_sel
	
	
logic_sel mov r12,#4
		  cmp r3, #6 
		  beq logic_or
		  
		  cmp r3, #5
		  beq logic_not
		  
		  cmp r3, #4
		  beq logic_nand
		  
		  cmp r3, #3
		  beq logic_nor
		  
		  cmp r3,#2
		  beq logic_xor
		  
		  cmp r3, #1
		  beq logic_xnor
		  
		  cmp r3, #0 
		  beq stop
	
	
	
stop	B stop; stop program	 
		 
     ENDFUNC
     END