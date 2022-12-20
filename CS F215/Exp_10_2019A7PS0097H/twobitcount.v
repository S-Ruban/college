`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:56:38 11/09/2020 
// Design Name: 
// Module Name:    twobitcount 
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
module twobitcount(
    input Clock,
    input Reset,
    output Q_A,
    output Q_B
    );

DD_FF_R D1(~Q_A, Clock, Reset, Q_A);
DD_FF_R D2(Q_A^Q_B, Clock, Reset, Q_B);

endmodule
