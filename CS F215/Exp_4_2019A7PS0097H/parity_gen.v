`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   07:54:40 09/21/2020
// Design Name:   Exp_4_2019A7PS0097H
// Module Name:   D:/College/CS/F215/Exp_4_2019A7PS0097H/parity_gen.v
// Project Name:  Exp_4_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Exp_4_2019A7PS0097H
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module parity_gen;

	// Inputs
	reg A;
	reg B;
	reg C;
	reg D;

	// Outputs
	wire P;

	// Instantiate the Unit Under Test (UUT)
	Exp_4_2019A7PS0097H uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.D(D), 
		.P(P)
	);

	initial begin
	
	// EVEN PARITY GENERATOR

		A = 0;
		B = 0;
		C = 0;
		D = 0;
		#10;
		
		A = 0;
		B = 0;
		C = 1;
		D = 0;
		#10;
		
		A = 0;
		B = 1;
		C = 0;
		D = 0;
		#10;
		
		A = 0;
		B = 1;
		C = 1;
		D = 0;
		#10;
		
		A = 1;
		B = 0;
		C = 0;
		D = 0;
		#10;
		
		A = 1;
		B = 0;
		C = 1;
		D = 0;
		#10;
		
		A = 1;
		B = 1;
		C = 0;
		D = 0;
		#10;
		
		A = 1;
		B = 1;
		C = 1;
		D = 0;
		#10;
		
		// ODD PARITY GENERATOR

		A = 0;
		B = 0;
		C = 0;
		D = 1;
		#10;
		
		A = 0;
		B = 0;
		C = 1;
		D = 1;
		#10;
		
		A = 0;
		B = 1;
		C = 0;
		D = 1;
		#10;
		
		A = 0;
		B = 1;
		C = 1;
		D = 1;
		#10;
		
		A = 1;
		B = 0;
		C = 0;
		D = 1;
		#10;
		
		A = 1;
		B = 0;
		C = 1;
		D = 1;
		#10;
		
		A = 1;
		B = 1;
		C = 0;
		D = 1;
		#10;
		
		A = 1;
		B = 1;
		C = 1;
		D = 1;
		#10;

      $finish ;		

	end
      
endmodule

