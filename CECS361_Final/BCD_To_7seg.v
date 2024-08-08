`timescale 1ns / 1ps

module BCD_To_7seg(
    input [3:0] Q,
    input reset,
    //input wire [1:0] states,
    input wire [2:0] Light_NS,
    input wire [2:0] Light_EW,
    output reg [7:0]cathode,
    output reg [7:0] anode
);

always @(*) begin
    if (reset) begin
      anode = 8'b1111_1111;
      cathode = 8'b00000000;
    //00 == Green/Red - go/stop
    //01 == Yellow/Red - stop/stop
    //10 == Red/Green - stop/go
    //11 == Red/Yellow - stop/stop
    end
    else begin
    if ((Light_NS <= 3'b010 ) && (Light_EW <= 3'b100)) begin
        // segment values for switch ON
        case (Q)
            4'b0000: begin
                anode = 8'b0111_1111;
                //cathode = 8'b01001001;//s
                cathode = 8'b00001001;//g
            end
            4'b0001: begin
                anode = 8'b1011_1111;
                cathode = 8'b11000101;//o
                //cathode = 8'b11100001;//t
            end
            4'b0010: begin
                anode = 8'b1111_0111;
                cathode = 8'b01001001;//s

            end
            4'b0011: begin
                anode = 8'b1111_1011;
                cathode = 8'b11100001;//t
            end
            4'b0100: begin
                anode = 8'b1111_1101;
                cathode = 8'b11000101;//o
                //cathode = 8'b00110001;//p
            end
            4'b0101: begin
                anode = 8'b11111110;
                cathode = 8'b00110001;//p
            end
            default: begin
                anode = 8'b1111_1111;
                cathode = 8'b00000000;
            end
        endcase
        
    end else if((Light_NS <= 3'b100 ) && (Light_EW <= 3'b010) ) begin
        case (Q)
                    4'b0000: begin
                        anode = 8'b0111_1111;
                        cathode = 8'b01001001;//s
        
                    end
                    4'b0001: begin
                        anode = 8'b1011_1111;
                        cathode = 8'b11100001;//t

                    end
                    4'b0010: begin
                        anode = 8'b1101_1111;
                        cathode = 8'b11000101;//o
                    end
                    4'b0011: begin
                        anode = 8'b1110_1111;
                        cathode = 8'b00110001;//p
                    end
                    4'b0100: begin
                        anode = 8'b1111_1101;
                        cathode = 8'b00001001;//g
                    end
                    4'b0101: begin
                        anode = 8'b1111_1110;
                        cathode = 8'b11000101;//o
                    end
                    default: begin
                        anode = 8'b1111_1111;
                        cathode = 8'b00000000;
                    end
            endcase
            
           
       end else begin
       case (Q)
                           4'b0000: begin
                               anode = 8'b0111_1111;
                               cathode = 8'b01001001;//s
                           end
                           4'b0001: begin
                               anode = 8'b1011_1111;
                               cathode = 8'b11100001;//t
                           end
                           4'b0010: begin
                               anode = 8'b1101_1111;
                               cathode = 8'b11000101;//o
                           end
                           4'b0011: begin
                               anode = 8'b1110_1111;
                               cathode = 8'b00110001;//p
                           end
                           
                           4'b0100: begin
                               anode = 8'b1111_0111;
                               cathode = 8'b01001001;//s
                           end
                           4'b0101: begin
                               anode = 8'b1111_1011;
                               cathode = 8'b11100001;//t
                           end
                           4'b0110: begin
                               anode = 8'b1111_1101;
                               cathode = 8'b11000101;//o
                           end
                           4'b0111: begin
                               anode = 8'b1110_1110;
                               cathode = 8'b00110001;//p
                           end
                           default: begin
                               anode = 8'b1111_1111;
                               cathode = 8'b00000000;
                           end
                   endcase
        
end
end
end

endmodule
