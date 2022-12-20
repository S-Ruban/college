`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    07:02:19 09/21/2020 
// Design Name: 
// Module Name:    Exp_4_2019A7PS0097H 
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
module Exp_4_2019A7PS0097H(
    input A,
    input B,
    input C,
    input D,
    output P
    );

wire w1, w2 ;
xor g1(w1, A, B);
xor g2(w2, w1, C);
xor g3(P, w2, D);

endmodule
