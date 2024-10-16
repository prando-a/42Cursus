FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install -y \
    php7.4-fpm \
    php7.4-mysql \
    php7.4-curl \
    php7.4-gd \
    php7.4-mbstring \
    unzip \
    wget \
    curl

RUN useradd wp_user && groupadd wp_group && usermod -aG wp_group wp_user

RUN mkdir -p /var/www/html && chown wp_user:wp_group /var/www/html

RUN mkdir /scripts

COPY tools/setup-wp.sh /scripts/setup-wp.sh
COPY tools/title.txt /scripts/title.txt
COPY config/php-fpm.conf /etc/php/7.4/fpm/php-fpm.conf
COPY config/wp-config.php /scripts/wp-config.php

RUN chmod +x /scripts/setup-wp.sh

EXPOSE 9000

CMD ["/scripts/setup-wp.sh"]
