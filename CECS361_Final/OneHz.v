`timescale 1ns / 1ps
/////////////////////////////////////////////////////////////////////////////
// Generates a 1Hz clock signal used to for the fsm
////////////////////////////////////////////////////////////////////////////
module OneHz(
    input clk,
    input reset,
    output clk_1Hz
    );
    
    reg clk_reg = 0;
    reg [25:0] count; // using 49999999 so 16 bits are needed
    always @(posedge clk) 
    begin 
        if (reset)
            count <= 0;
        else
            if(count == 49_999_999)
            begin
                count <= 0;
                clk_reg <= ~clk_reg;
            end
            else
                count <= count + 1;
    end
    assign clk_1Hz = clk_reg;
    
endmodule
