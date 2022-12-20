`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    08:14:52 10/27/2020 
// Design Name: 
// Module Name:    FullAdder 
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
module FullAdder(
    input A,
    input B,
    input C,
    output Sum,
    output Carry
    );

Mux m1 (150, {A,B,C}, Sum);   // 150 = 128+16+4+2 = 2^7 + 2^4 + 2^2 + 2^1 => m1+m2+m4+m7
Mux m2 (232, {A,B,C}, Carry); // 232 = 128+54+32+8 = 2^7 + 2^6 + 2^5 + 2^3 => m3+m5+m6+m7

endmodule
