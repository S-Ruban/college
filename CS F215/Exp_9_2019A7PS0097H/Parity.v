`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:15:17 10/26/2020 
// Design Name: 
// Module Name:    Parity 
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
module Parity(
    input [2:0] A,
    output F
    );

wire [0:7] d;
decoder d1(A, d);
assign F = ~(d[0]|d[3]|d[5]|d[6]);

endmodule
