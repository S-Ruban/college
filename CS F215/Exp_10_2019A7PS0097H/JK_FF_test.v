`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:32:59 11/09/2020
// Design Name:   JK_FF
// Module Name:   D:/College/CS/F215/Exp_10_2019A7PS0097H/JK_FF_test.v
// Project Name:  Exp_10_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: JK_FF
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module JK_FF_test;

	// Inputs
	reg J;
	reg K;
	reg Clk;
	reg Reset;

	// Outputs
	wire Q;
	wire Qbar;

	// Instantiate the Unit Under Test (UUT)
	JK_FF uut (
		.J(J), 
		.K(K), 
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
		#100 Clk = ~Clk ;
		end
		
		initial begin
		J = 0 ;
		repeat (6)
		#150 J = ~J ;
		end
		
		initial begin
		K = 0 ;
		repeat (12)
		#75 K = ~K ;
		end
      
endmodule

