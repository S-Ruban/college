`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   08:25:26 10/27/2020
// Design Name:   FullAdder
// Module Name:   D:/College/CS/F215/Exp_9_2019A7PS0097H/fulladdertest.v
// Project Name:  Exp_9_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: FullAdder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module fulladdertest;

	// Inputs
	reg A;
	reg B;
	reg C;

	// Outputs
	wire Sum;
	wire Carry;

	// Instantiate the Unit Under Test (UUT)
	FullAdder uut (
		.A(A), 
		.B(B), 
		.C(C), 
		.Sum(Sum), 
		.Carry(Carry)
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

