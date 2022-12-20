`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:40:12 09/24/2020 
// Design Name: 
// Module Name:    Exp_4_2019A7PS0097H_2 
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
module Exp_4_2019A7PS0097H_2(
    input A,
    input B,
    input C,
    output M
    );

wire w1, w2, w3, w4 ;
and(w1,A,B);
and(w2,B,C);
and(w3,C,A);
or(w4,w1,w2);
or(M,w4,w3);

endmodule
