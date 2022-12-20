`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:30:42 11/09/2020 
// Design Name: 
// Module Name:    JK_FF 
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
module JK_FF(
    input J,
    input K,
    input Clk,
    input Reset,
    output Q,
    output Qbar
    );

DD_FF_R D((J&(~Q)|(~K&Q)), Clk, Reset, Q);
assign Qbar = ~Q ;

endmodule
