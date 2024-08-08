`timescale 1ns / 1ps

module Traffic_Control_top(
    input reset,
    input clk,
    //input [1:0] states,
    input [1:0] switch,
    output [2:0] Light_NS,
    output [2:0] Light_EW,
    output [7:0] cathode,
    output [7:0] anode
    );
    
    //wire [1:0] states;
    wire OneHz_wire;
   // wire [1:0] states;
   // wire reset_wire;
    wire [7:0] anode;
    wire [7:0] cathode; 
    wire [3:0] Q; 
    
    
        
    BCD_To_7seg BCD(.reset(reset), .Q(Q), .Light_NS(Light_NS), .Light_EW(Light_EW), .cathode(cathode), .anode(anode));
    Sync_BCD_Counter counter(.clk(clk), .reset(reset), .Q(Q));
    
    Traffic_Light TL(.switch(switch), .reset(reset), .clk(OneHz_wire), .Light_NS(Light_NS), .Light_EW(Light_EW));
    OneHz One( .clk(clk), .reset(reset), .clk_1Hz(OneHz_wire));
    
endmodule
