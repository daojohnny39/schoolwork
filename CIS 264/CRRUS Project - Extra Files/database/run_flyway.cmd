ECHO OFF
set FLYWAY_HOME=C:\Users\liyin\Documents\ProgramClasses\CIS264ApplicationDevelopment\flyway-9.22.0

@REM This command will allow paramters to be passed such as info or migrate
%FLYWAY_HOME%\flyway.cmd -configFiles="./conf/flyway_sqlite.conf" %1 %2 %3 %4