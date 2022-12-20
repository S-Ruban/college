`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:59:15 10/26/2020
// Design Name:   decoder
// Module Name:   D:/College/CS/F215/Exp_9_2019A7PS0097H/decode_3x8.v
// Project Name:  Exp_9_2019A7PS0097H
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: decoder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module decode_3x8;

	// Inputs
	reg [2:0] in;

	// Outputs
	wire [7:0] out;

	// Instantiate the Unit Under Test (UUT)
	decoder uut (
		.in(in), 
		.out(out)
	);

	initial begin
	
		in = 0;
		#10;
		
		in = 1;
		#10;
		
		in = 2;
		#10;
		
		in = 3;
		#10;
		
		in = 4;
		#10;
		
		in = 5;
		#10;
		
		in = 6;
		#10;
		
		in = 7;
		#10;
        
		 $finish ;

	end
      
endmodule

