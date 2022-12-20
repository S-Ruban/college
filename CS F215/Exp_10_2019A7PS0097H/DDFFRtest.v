`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:40:42 10/29/2020
// Design Name:   DD_FF_R
// Module Name:   D:/College/CS/F215/Exp_10_2019A7PS0097H/DDFFRtest.v
// Project Name:  Exp_10_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: DD_FF_R
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module DDFFRtest;

	// Inputs
	reg D;
	reg Clk;
	reg Reset;

	// Outputs
	wire Q;

	// Instantiate the Unit Under Test (UUT)
	DD_FF_R uut (
		.D(D), 
		.Clk(Clk), 
		.Reset(Reset), 
		.Q(Q)
	);

	initial begin
		
		Clk = 0 ;
		repeat (9)
		#100 Clk = ~Clk ;
		end
		initial begin
		D = 0;
		repeat (6)
		#225 D = ~ D;
		end
		initial begin
		Reset = 0;
		repeat (6)
		#125 Reset = ~ Reset;

	end
      
endmodule

