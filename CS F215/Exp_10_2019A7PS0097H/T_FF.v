`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:09:16 11/09/2020 
// Design Name: 
// Module Name:    T_FF 
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
module T_FF(
    input T,
    input Clk,
    input Reset,
    output Q,
    output Qbar
    );

DD_FF_R D(T^Q, Clk, Reset, Q);
assign Qbar = ~Q ;

endmodule
