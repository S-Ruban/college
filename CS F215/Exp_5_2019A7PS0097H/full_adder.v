`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:15:24 09/27/2020
// Design Name:   fa
// Module Name:   D:/College/CS/F215/Exp_5_2019A7PS0097H/full_adder.v
// Project Name:  Exp_5_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: fa
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module full_adder;

	// Inputs
	reg A;
	reg B;
	reg C_in;

	// Outputs
	wire S;
	wire C;

	// Instantiate the Unit Under Test (UUT)
	fa uut (
		.A(A), 
		.B(B), 
		.C_in(C_in), 
		.S(S), 
		.C(C)
	);

	initial begin
		
		A = 0;
		B = 0;
		C_in = 0;
		#10;
		
		A = 0;
		B = 0;
		C_in = 1;
		#10;
		
		A = 0;
		B = 1;
		C_in = 0;
		#10;
		
		A = 0;
		B = 1;
		C_in = 1;
		#10;
		
		A = 1;
		B = 0;
		C_in = 0;
		#10;
		
		A = 1;
		B = 0;
		C_in = 1;
		#10;
		
		A = 1;
		B = 1;
		C_in = 0;
		#10;
		
		A = 1;
		B = 1;
		C_in = 1;
		#10;
        
		$finish ;

	end
      
endmodule

