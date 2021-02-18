library verilog;
use verilog.vl_types.all;
entity mux_1_bit_2_1 is
    port(
        i1              : in     vl_logic;
        i2              : in     vl_logic;
        select_b        : in     vl_logic;
        \out\           : out    vl_logic
    );
end mux_1_bit_2_1;
