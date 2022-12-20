`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:20:20 11/09/2020
// Design Name:   twobitcount
// Module Name:   D:/College/CS/F215/Exp_10_2019A7PS0097H/twobitcounttest.v
// Project Name:  Exp_10_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: twobitcount
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module twobitcounttest;

	// Inputs
	reg Clock;
	reg Reset;

	// Outputs
	wire Q_A;
	wire Q_B;

	// Instantiate the Unit Under Test (UUT)
	twobitcount uut (
		.Clock(Clock), 
		.Reset(Reset), 
		.Q_A(Q_A), 
		.Q_B(Q_B)
	);

		initial begin
		
		Reset = 0 ;
		repeat (2)
		#1 Reset = ~Reset ;
		end
		
	initial begin
	
		Clock = 0 ;
		repeat (9)
		#100 Clock = ~ Clock ;
		end

      
endmodule

