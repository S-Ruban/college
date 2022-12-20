`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:17:06 11/09/2020
// Design Name:   T_FF
// Module Name:   D:/College/CS/F215/Exp_10_2019A7PS0097H/T_FF_test.v
// Project Name:  Exp_10_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: T_FF
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_FF_test;

	// Inputs
	reg T;
	reg Clk;
	reg Reset;

	// Outputs
	wire Q;
	wire Qbar;

	// Instantiate the Unit Under Test (UUT)
	T_FF uut (
		.T(T), 
		.Clk(Clk), 
		.Reset(Reset), 
		.Q(Q), 
		.Qbar(Qbar)
	);

		initial begin
		
		Reset = 0 ;
		repeat (2)
		#1 Reset = ~Reset ;
		end
		
	initial begin
	
		Clk = 0 ;
		repeat (9)
		#100 Clk = ~ Clk ;
		end
		
		initial begin
		T = 0 ;
		repeat (5)
		#200 T = ~T ;
		end
      
endmodule

