library verilog;
use verilog.vl_types.all;
entity extend_16_to_32 is
    port(
        i1              : in     vl_logic_vector(15 downto 0);
        sign            : in     vl_logic;
        \out\           : out    vl_logic_vector(31 downto 0)
    );
end extend_16_to_32;
