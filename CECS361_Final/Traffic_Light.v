`timescale 1ns / 1ps

module Traffic_Light(
    input clk, reset,[1:0] switch,
    output reg [2:0] Light_NS,
    output reg [2:0] Light_EW
    );
    
    // Traffic light FSM  
    reg [1:0] states;
    localparam s0 = 2'b00,
               s1 = 2'b01,
               s2 = 2'b10,
               s3 = 2'b11;
               
    // count used for time delay 32 bit for 29 total sec
    reg [5:0] count = 0;
                          
    // initiate state at s0 on reset                     
    always @(posedge clk || reset)
        if (reset) begin 
            states <= s0;
            end
        else // state cases used to transition from each state
             // via time delay
             //switch[0] = crossing N/S => Make Red/Green (S2)
             //switch[1] = crossing E/W => Make Green/Red (S0)
            case(states)
                s0: if(count == 9 || (switch[1] && states<=s0)) begin // after 10s pass move to next state 
                        states <= s1;
                        end
                        
                s1: if(count == 13)// after 3s pass move to next state
                       states <= s2;
                       
                s2: if(count == 25 || (switch[0] && states<=s2))begin // after 10s pass move to next state 
                      states <= s3;
                       end
                s3: if(count == 29)  // after 3s pass move to next state 
                       states <= s0; 
                default : states <= s0;    
            endcase 
        
        // simple count used to loop through the states
        always @(posedge clk || reset)
        begin 
            if(reset)
                count <= 0;
            else
                if(count == 29)
                    count <= 0;
                else
                    count <= count + 1;
        end
        
        always @(posedge clk || reset)
            begin 
            // FSM states corresponding with lights
            // North and South (NS)
            // East and West (EW) 
            case(states)
                    // output is the rgb lights
                s0: begin 
                    Light_NS <= 3'b010; // green
                    Light_EW <= 3'b100; // red
                    end   
                s1: begin 
                    Light_NS <= 3'b110; // yellow
                    Light_EW <= 3'b100; // red
                    end
                s2: begin 
                    Light_NS <= 3'b100; // red
                    Light_EW <= 3'b010; // green
                    end
                s3: begin 
                    Light_NS <= 3'b100; // red
                    Light_EW <= 3'b110; // yellow
                    end  
                default begin Light_NS <= 3'b010; // green 
                              Light_EW <= 3'b001; // red
                        end
            endcase
        end               
endmodule
