`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:46:44 10/29/2020 
// Design Name: 
// Module Name:    DFF_CLK 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module DFF_CLK(
    input D,
    input Clk,
    output reg Q,
	 output reg Qbar
    );

always @ (posedge Clk)
	begin
		Q <= D;
		assign Qbar = ~Q ;
	end

endmodule
