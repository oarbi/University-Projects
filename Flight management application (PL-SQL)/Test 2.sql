declare
    d number;
    nv varchar2(20) :='25:25';
begin
    d :=  to_number(substr(nv,1,instr(nv,':')-1))*60 + to_number(substr(nv,instr(nv,':')+1,2));
    dbms_output.put_line(d);
end;