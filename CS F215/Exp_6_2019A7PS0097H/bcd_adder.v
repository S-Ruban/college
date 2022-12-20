`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:57:17 09/27/2020 
// Design Name: 
// Module Name:    bcd_adder 
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
module bcd_adder(
    input [3:0] A,
    input [3:0] B,
    output [3:0] S,
    output C_out
    );

wire [3:0] Z ;
wire w1, w2 ;
fba a1(A,B,Z,w1);
assign w2=(Z[3]&Z[2])|(Z[1]&Z[3]);
assign Carry = w1|w2 ;
wire [3:0] C ;
assign C={1'b0, Carry, Carry, 1'b0};
fba a2(Z,C,S,C_out);

endmodule
