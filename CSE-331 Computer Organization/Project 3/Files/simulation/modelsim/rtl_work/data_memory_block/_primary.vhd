library verilog;
use verilog.vl_types.all;
entity data_memory_block is
    port(
        address         : in     vl_logic_vector(31 downto 0);
        write_data      : in     vl_logic_vector(31 downto 0);
        mem_write_sg    : in     vl_logic;
        read_data       : out    vl_logic_vector(31 downto 0);
        clock           : in     vl_logic
    );
end data_memory_block;
