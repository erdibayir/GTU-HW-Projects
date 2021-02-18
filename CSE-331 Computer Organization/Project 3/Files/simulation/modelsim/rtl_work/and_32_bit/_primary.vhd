library verilog;
use verilog.vl_types.all;
entity and_32_bit is
    port(
        i1              : in     vl_logic_vector(31 downto 0);
        i2              : in     vl_logic_vector(31 downto 0);
        \out\           : out    vl_logic_vector(31 downto 0)
    );
end and_32_bit;
