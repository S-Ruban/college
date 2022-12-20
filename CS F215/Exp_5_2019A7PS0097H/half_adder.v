`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:13:05 09/27/2020
// Design Name:   ha
// Module Name:   D:/College/CS/F215/Exp_5_2019A7PS0097H/half_adder.v
// Project Name:  Exp_5_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ha
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module half_adder;

	// Inputs
	reg a;
	reg b;

	// Outputs
	wire c;
	wire s;

	// Instantiate the Unit Under Test (UUT)
	ha uut (
		.a(a), 
		.b(b), 
		.c(c), 
		.s(s)
	);

	initial begin
		
		a = 0;
		b = 0;
		#10;
        
		a = 0;
		b = 1;
		#10;
		
		a = 1;
		b = 0;
		#10;
		
		a = 1;
		b = 1;
		#10;
		
		$finish ;

	end
      
endmodule

