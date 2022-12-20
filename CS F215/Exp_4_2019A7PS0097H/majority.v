`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:42:46 09/24/2020
// Design Name:   Exp_4_2019A7PS0097H_2
// Module Name:   D:/College/CS/F215/Exp_4_2019A7PS0097H/majority.v
// Project Name:  Exp_4_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Exp_4_2019A7PS0097H_2
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module majority;

	// Inputs
	reg A;
	reg B;
	reg C;

	// Outputs
	wire M;

	// Instantiate the Unit Under Test (UUT)
	Exp_4_2019A7PS0097H_2 uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.M(M)
	);

	initial begin
	
		A = 0;
		B = 0;
		C = 0;
		#10;
		
		A = 0;
		B = 0;
		C = 1;
		#10;
		
		A = 0;
		B = 1;
		C = 0;
		#10;
		
		A = 0;
		B = 1;
		C = 1;
		#10;
		
		A = 1;
		B = 0;
		C = 0;
		#10;
		
		A = 1;
		B = 0;
		C = 1;
		#10;
		
		A = 1;
		B = 1;
		C = 0;
		#10;
		
		A = 1;
		B = 1;
		C = 1;
		#10;

		$finish ;
		
	end
      
endmodule

