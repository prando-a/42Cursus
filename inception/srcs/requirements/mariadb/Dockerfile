FROM debian:bullseye

ARG DB_NAME
ARG DB_USER
ARG DB_PASS
ARG DB_ROOT_PASS

ENV DB_NAME=$DB_NAME \
    DB_USER=$DB_USER \
    DB_PASS=$DB_PASS \
    DB_ROOT_PASS=$DB_ROOT_PASS

RUN apt-get update && \
    apt upgrade -y && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY ./config/my.cnf /etc/mysql/my.cnf

RUN mkdir -p /var/run/mysqld/
RUN chown -R mysql:mysql /var/run/mysqld/

EXPOSE 3306

RUN service mariadb start && \
    echo "CREATE DATABASE IF NOT EXISTS ${DB_NAME} ;" > msql_db.sql && \
    echo "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASS}' ;" >> msql_db.sql && \
    echo "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%' ;" >> msql_db.sql && \
    echo "FLUSH PRIVILEGES;" >> msql_db.sql && \
    echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASS}' ;" >> msql_db.sql && \
    mariadb < msql_db.sql

CMD ["mysqld"]

