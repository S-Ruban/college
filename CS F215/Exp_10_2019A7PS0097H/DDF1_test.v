`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:51:37 10/29/2020
// Design Name:   DFF_CLK
// Module Name:   D:/College/CS/F215/Exp_10_2019A7PS0097H/DDF1_test.v
// Project Name:  Exp_10_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: DFF_CLK
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module DDF1_test;

	// Inputs
	reg D;
	reg Clk;

	// Outputs
	wire Q;
	wire Qbar;

	// Instantiate the Unit Under Test (UUT)
	DFF_CLK uut (
		.D(D), 
		.Clk(Clk), 
		.Q(Q),
		.Qbar(Qbar)
	);

	initial begin
	
	Clk = 0 ;
	repeat (9)
	#100 Clk = ~ Clk ;
	end
	
	initial begin
	D = 0;
	repeat (6)
	#225 D = ~ D;
	end
      
endmodule

