<?php


use \WebPExpress\Paths;

if (empty(get_option('webp-express-configured'))) {
    echo '<div style="background-color: #cfc; padding: 20px; border: 1px solid #ccc">';
    echo '<h3>Welcome!<h3>';
    echo '<p>The rewrite rules are not active yet. They will be activated the first time you click the "Save settings" button.</p>';
    echo '<p>Before you do that, I suggest you find out which converters that works. Start from the top. Click "test" next to a converter to test it. Try also clicking the "configure" buttons</p>';
    echo '</div>';
}

function webpexpress_display_notice($level, $message, $escHtml = true) {
    $msg = __( $message, 'webp-express');
    if ($escHtml) {
        $msg = esc_html($msg);
    }
    printf(
        '<div class="%1$s"><p>%2$s</p></div>',
        esc_attr('notice notice-' . $level . ' is-dismissible'),
        $msg
    );
}

if (!Paths::createContentDirIfMissing()) {
    webpexpress_display_notice(
        'error',
        'WebP Express needs to create a directory "webp-express" under your wp-content folder, but does not have permission to do so.<br>' .
            'Please create the folder manually, or change the file permissions of your wp-content folder.',
        false
    );
} else {
    if (!Paths::createConfigDirIfMissing()) {
        webpexpress_display_notice(
            'error',
            'WebP Express needs to create a directory "webp-express/config" under your wp-content folder, but does not have permission to do so.<br>' .
                'Please create the folder manually, or change the file permissions.',
            false
        );
    }

    if (!Paths::createCacheDirIfMissing()) {
        webpexpress_display_notice(
            'error',
            'WebP Express needs to create a directory "webp-express/webp-images" under your wp-content folder, but does not have permission to do so.<br>' .
                'Please create the folder manually, or change the file permissions.',
            false
        );
    }
}