`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:25:14 10/26/2020
// Design Name:   Parity
// Module Name:   D:/College/CS/F215/Exp_9_2019A7PS0097H/Parity_test.v
// Project Name:  Exp_9_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Parity
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Parity_test;

	// Inputs
	reg [2:0] A;

	// Outputs
	wire F;

	// Instantiate the Unit Under Test (UUT)
	Parity uut (
		.A(A), 
		.F(F)
	);

	initial begin
		
		A = 0;
		#10;
		
		A = 1;
		#10;
		
		A = 2;
		#10;
		
		A = 3;
		#10;
		
		A = 4;
		#10;
		
		A = 5;
		#10;
		
		A = 6;
		#10;
		
		A = 7;
		#10;
        
		 $finish ;

	end
      
endmodule

