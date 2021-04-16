library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decoder3_8 is
    Port ( a : in  STD_LOGIC_VECTOR (2 downto 0);
           y : out  STD_LOGIC_VECTOR (7 downto 0));
end decoder3_8;

architecture Behavioral of decoder3_8 is

		begin
		y(0) <=not a(0) and not a(1) and not a(2);
		y(1) <=not a(0) and not a(1) and  a(2);
		y(2) <=not a(0) and  a(1) and not a(2);
		y(3) <=not a(0) and  a(1) and a(2);
		y(4) <= a(0) and not a(1) and not a(2);
		y(5) <= a(0) and not a(1) and  a(2);
		y(6) <= a(0) and  a(1) and not a(2);
		y(7) <= a(0) and  a(1) and  a(2);

		end Behavioral;
