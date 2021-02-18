library verilog;
use verilog.vl_types.all;
entity program_counter_block is
    port(
        clock           : in     vl_logic;
        new_instruction : out    vl_logic_vector(31 downto 0)
    );
end program_counter_block;
