library verilog;
use verilog.vl_types.all;
entity alu_32_bit is
    port(
        i1              : in     vl_logic_vector(31 downto 0);
        i2              : in     vl_logic_vector(31 downto 0);
        alu_op          : in     vl_logic_vector(2 downto 0);
        zero_bit        : out    vl_logic_vector(31 downto 0);
        \out\           : out    vl_logic_vector(31 downto 0)
    );
end alu_32_bit;
