library verilog;
use verilog.vl_types.all;
entity alu_control_unit is
    port(
        alu_Op          : in     vl_logic_vector(1 downto 0);
        function_field  : in     vl_logic_vector(5 downto 0);
        alu_Op_out      : out    vl_logic_vector(2 downto 0)
    );
end alu_control_unit;
