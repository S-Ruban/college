`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:11:31 09/27/2020
// Design Name:   ha
// Module Name:   D:/College/CS/F215/Exp_5_2019A7PS0097H/half_adeer.v
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

module half_adeer;

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

