`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:10:22 09/27/2020 
// Design Name: 
// Module Name:    fa 
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
module fa(
    input A, B, C_in,
    output S, C
    );

wire S1, C1, C2 ;
ha g1(A,B,C1,S1);
ha g2(S1,C_in,C2,S);
assign C = C1|C2 ;

endmodule
