library verilog;
use verilog.vl_types.all;
entity register_block is
    port(
        clock           : in     vl_logic;
        read_reg_1      : in     vl_logic_vector(4 downto 0);
        read_reg_2      : in     vl_logic_vector(4 downto 0);
        write_register1 : in     vl_logic_vector(4 downto 0);
        write_register2 : in     vl_logic_vector(4 downto 0);
        read_data_1     : out    vl_logic_vector(31 downto 0);
        read_data_2     : out    vl_logic_vector(31 downto 0);
        signal_reg_write: in     vl_logic;
        write_data1     : in     vl_logic_vector(31 downto 0);
        write_data2     : in     vl_logic_vector(31 downto 0)
    );
end register_block;
