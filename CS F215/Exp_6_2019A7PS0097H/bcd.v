`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   08:03:28 10/01/2020
// Design Name:   bcd_adder
// Module Name:   D:/College/CS/F215/Exp_6_2019A7PS0097H/bcd.v
// Project Name:  Exp_6_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: bcd_adder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module bcd;

	// Inputs
	reg [3:0] A;
	reg [3:0] B;

	// Outputs
	wire [3:0] S;
	wire C_out;

	// Instantiate the Unit Under Test (UUT)
	bcd_adder uut (
		.A(A), 
		.B(B), 
		.S(S), 
		.C_out(C_out)
	);

	initial begin
		
		A = 0 ;
		B = 0 ;
		#10 ;

		A = 0 ;
		B = 1 ;
		#10 ;

		A = 0 ;
		B = 2 ;
		#10 ;

		A = 0 ;
		B = 3 ;
		#10 ;

		A = 0 ;
		B = 4 ;
		#10 ;

		A = 0 ;
		B = 5 ;
		#10 ;

		A = 0 ;
		B = 6 ;
		#10 ;

		A = 0 ;
		B = 7 ;
		#10 ;

		A = 0 ;
		B = 8 ;
		#10 ;

		A = 0 ;
		B = 9 ;
		#10 ;


		A = 1 ;
		B = 0 ;
		#10 ;

		A = 1 ;
		B = 1 ;
		#10 ;

		A = 1 ;
		B = 2 ;
		#10 ;

		A = 1 ;
		B = 3 ;
		#10 ;

		A = 1 ;
		B = 4 ;
		#10 ;

		A = 1 ;
		B = 5 ;
		#10 ;

		A = 1 ;
		B = 6 ;
		#10 ;

		A = 1 ;
		B = 7 ;
		#10 ;

		A = 1 ;
		B = 8 ;
		#10 ;

		A = 1 ;
		B = 9 ;
		#10 ;


		A = 2 ;
		B = 0 ;
		#10 ;

		A = 2 ;
		B = 1 ;
		#10 ;

		A = 2 ;
		B = 2 ;
		#10 ;

		A = 2 ;
		B = 3 ;
		#10 ;

		A = 2 ;
		B = 4 ;
		#10 ;

		A = 2 ;
		B = 5 ;
		#10 ;

		A = 2 ;
		B = 6 ;
		#10 ;

		A = 2 ;
		B = 7 ;
		#10 ;

		A = 2 ;
		B = 8 ;
		#10 ;

		A = 2 ;
		B = 9 ;
		#10 ;


		A = 3 ;
		B = 0 ;
		#10 ;

		A = 3 ;
		B = 1 ;
		#10 ;

		A = 3 ;
		B = 2 ;
		#10 ;

		A = 3 ;
		B = 3 ;
		#10 ;

		A = 3 ;
		B = 4 ;
		#10 ;

		A = 3 ;
		B = 5 ;
		#10 ;

		A = 3 ;
		B = 6 ;
		#10 ;

		A = 3 ;
		B = 7 ;
		#10 ;

		A = 3 ;
		B = 8 ;
		#10 ;

		A = 3 ;
		B = 9 ;
		#10 ;


		A = 4 ;
		B = 0 ;
		#10 ;

		A = 4 ;
		B = 1 ;
		#10 ;

		A = 4 ;
		B = 2 ;
		#10 ;

		A = 4 ;
		B = 3 ;
		#10 ;

		A = 4 ;
		B = 4 ;
		#10 ;

		A = 4 ;
		B = 5 ;
		#10 ;

		A = 4 ;
		B = 6 ;
		#10 ;

		A = 4 ;
		B = 7 ;
		#10 ;

		A = 4 ;
		B = 8 ;
		#10 ;

		A = 4 ;
		B = 9 ;
		#10 ;


		A = 5 ;
		B = 0 ;
		#10 ;

		A = 5 ;
		B = 1 ;
		#10 ;

		A = 5 ;
		B = 2 ;
		#10 ;

		A = 5 ;
		B = 3 ;
		#10 ;

		A = 5 ;
		B = 4 ;
		#10 ;

		A = 5 ;
		B = 5 ;
		#10 ;

		A = 5 ;
		B = 6 ;
		#10 ;

		A = 5 ;
		B = 7 ;
		#10 ;

		A = 5 ;
		B = 8 ;
		#10 ;

		A = 5 ;
		B = 9 ;
		#10 ;


		A = 6 ;
		B = 0 ;
		#10 ;

		A = 6 ;
		B = 1 ;
		#10 ;

		A = 6 ;
		B = 2 ;
		#10 ;

		A = 6 ;
		B = 3 ;
		#10 ;

		A = 6 ;
		B = 4 ;
		#10 ;

		A = 6 ;
		B = 5 ;
		#10 ;

		A = 6 ;
		B = 6 ;
		#10 ;

		A = 6 ;
		B = 7 ;
		#10 ;

		A = 6 ;
		B = 8 ;
		#10 ;

		A = 6 ;
		B = 9 ;
		#10 ;


		A = 7 ;
		B = 0 ;
		#10 ;

		A = 7 ;
		B = 1 ;
		#10 ;

		A = 7 ;
		B = 2 ;
		#10 ;

		A = 7 ;
		B = 3 ;
		#10 ;

		A = 7 ;
		B = 4 ;
		#10 ;

		A = 7 ;
		B = 5 ;
		#10 ;

		A = 7 ;
		B = 6 ;
		#10 ;

		A = 7 ;
		B = 7 ;
		#10 ;

		A = 7 ;
		B = 8 ;
		#10 ;

		A = 7 ;
		B = 9 ;
		#10 ;


		A = 8 ;
		B = 0 ;
		#10 ;

		A = 8 ;
		B = 1 ;
		#10 ;

		A = 8 ;
		B = 2 ;
		#10 ;

		A = 8 ;
		B = 3 ;
		#10 ;

		A = 8 ;
		B = 4 ;
		#10 ;

		A = 8 ;
		B = 5 ;
		#10 ;

		A = 8 ;
		B = 6 ;
		#10 ;

		A = 8 ;
		B = 7 ;
		#10 ;

		A = 8 ;
		B = 8 ;
		#10 ;

		A = 8 ;
		B = 9 ;
		#10 ;


		A = 9 ;
		B = 0 ;
		#10 ;

		A = 9 ;
		B = 1 ;
		#10 ;

		A = 9 ;
		B = 2 ;
		#10 ;

		A = 9 ;
		B = 3 ;
		#10 ;

		A = 9 ;
		B = 4 ;
		#10 ;

		A = 9 ;
		B = 5 ;
		#10 ;

		A = 9 ;
		B = 6 ;
		#10 ;

		A = 9 ;
		B = 7 ;
		#10 ;

		A = 9 ;
		B = 8 ;
		#10 ;

		A = 9 ;
		B = 9 ;
		#10 ;
		
		$finish ;

	end
      
endmodule

