`timescale 1ns/1ps
`include "GROM1.v"

/*
    input clk,
    input [31:0] ADDR,
    input [31:0] Din,
    input Enable,
    input CNTRL,
    output [31:0] read_data
*/

module GROM_tb();
    reg clk;
    reg [31:0] ADDR;
    reg [31:0] Din;
    reg Enable; 
    reg [1:0] CNTRL;
    wire [31:0] read_data;
    wire status;

    grom_x dut(
        .clk(clk),
        .ADDR(ADDR),
        .CNTRL(CNTRL),
        .status(status),
        .read_data(read_data),
        .Din(Din),
        .Enable(Enable)
    );

    initial begin
        clk = 1; #10;
        ADDR = 32'd324; CNTRL = 2'b01;Enable = 1'b1; #10; // Read at ADDR 324
        CNTRL = 2'b00;#10;
        ADDR = 32'd324; CNTRL = 2'b10 ;Din = 32'd345; #10; // Write at ADDR 324 the value of "345"
        CNTRL = 32'b00;#10;
        ADDR = 32'd324; CNTRL = 2'b01;Enable = 1'b1; #10;
        CNTRL = 2'b00;#10;
        Enable = 1'b0;
        #10;
        $finish;
         
    end 

    always #5 clk = ~clk;
    
endmodule