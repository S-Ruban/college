`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:42:05 10/29/2020
// Design Name:   D_latch
// Module Name:   D:/College/CS/F215/Exp_10_2019A7PS0097H/dlatch.v
// Project Name:  Exp_10_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: D_latch
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module dlatch;

	// Inputs
	reg D;
	reg En;

	// Outputs
	wire Q;
	wire Qbar;

	// Instantiate the Unit Under Test (UUT)
	D_latch uut (
		.D(D), 
		.En(En), 
		.Q(Q), 
		.Qbar(Qbar)
	);

	initial begin

		D = 0 ;
		En = 1 ;
		#10 ;
		
		D = 0 ;
		En = 0 ;
		#10 ;
		
		D = 1 ;
		En = 0 ;
		#10 ;
		
		D = 1 ;
		En = 1 ;
		#10 ;
		
		$finish ;

	end
      
endmodule

