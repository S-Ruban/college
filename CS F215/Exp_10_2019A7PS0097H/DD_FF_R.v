`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:39:18 10/29/2020 
// Design Name: 
// Module Name:    DD_FF_R 
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
module DD_FF_R(
    input D,
    input Clk,
    input Reset,
    output reg Q
    );

	always @ (posedge Clk , posedge Reset)
	begin
	if (Reset==1)
	Q <= 1'b0;
	else
	Q <= D;
	end

endmodule
