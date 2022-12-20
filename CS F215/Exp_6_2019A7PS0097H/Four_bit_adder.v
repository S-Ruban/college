`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:22:20 09/27/2020 
// Design Name: 
// Module Name:    fba 
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
module fba(
    input [3:0] A,
    input [3:0] B,
    output [3:0] Sum,
    output Carry
    );

assign {Carry,Sum} = A+B ;

endmodule
