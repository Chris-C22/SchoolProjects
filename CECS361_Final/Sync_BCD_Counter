//Sync_BCD_Counter.v

`timescale 1ns / 1ps

module Sync_BCD_Counter (
    input clk, 
    input reset, 
    output reg [3:0] Q
);

reg [26:0] counter; //What size?

    always@(posedge clk, posedge reset) begin
        if(reset) begin
            counter <= 27'b0; //What size?
            Q <= 4'b0;
        end
        else if(counter == 100_000) begin //How much should we wait?  Imporant note: For simulation purpose, choose a very small counter. After you verify the functionality of the module via simulation, change the counter to the value that is required to be run on the board with 100Mhz clock.
            counter <= 27'b0; //Reset the counter
            if(Q < 9) //What is the max decimal number in BCD counter?
                Q <= Q + 1'b1;
            else 
                Q <= 4'b0;
        end
        else
            counter <= counter + 1'b1;
       end
endmodule
