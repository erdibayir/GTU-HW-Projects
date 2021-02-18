library verilog;
use verilog.vl_types.all;
entity mux_5_bit_2_1 is
    port(
        i1              : in     vl_logic_vector(4 downto 0);
        i2              : in     vl_logic_vector(4 downto 0);
        \out\           : out    vl_logic_vector(4 downto 0);
        select_b        : in     vl_logic
    );
end mux_5_bit_2_1;
