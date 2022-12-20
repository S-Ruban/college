`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    07:46:51 10/28/2020 
// Design Name: 
// Module Name:    D_latch 
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
module D_latch(
    input D,
    input En,
    output Q,
    output Qbar
    );
	 
//assign Q = 0, Qbar = 1 ;
wire Dn, W1, W2 ;
not n1(Dn, D);
nand n2(W1, D, En);
nand n3(W2, Dn, En);
nand n4(Q, W1, Qbar);
nand n5(Qbar, W2, Q);

endmodule
