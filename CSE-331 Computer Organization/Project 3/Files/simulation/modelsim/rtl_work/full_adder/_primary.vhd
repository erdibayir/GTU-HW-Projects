library verilog;
use verilog.vl_types.all;
entity full_adder is
    port(
        x               : in     vl_logic;
        y               : in     vl_logic;
        cin             : in     vl_logic;
        s               : out    vl_logic;
        cout            : out    vl_logic
    );
end full_adder;
