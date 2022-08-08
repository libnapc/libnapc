#!/bin/bash -x

php -S 127.0.0.1:9999 index.php &

php_server_pid="$!"

php ./export.php --optimized

exit_code="$?"

echo "export.php exited with $exit_code"

kill -9 "$php_server_pid"

exit "$exit_code"
