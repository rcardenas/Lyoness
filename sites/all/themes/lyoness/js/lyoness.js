Drupal.behaviors.lyoness = function(context)
{
  // expandable menus
  $('#block-menu-primary-links .expanded:not(.active-trail) ul').hide();
  $('#block-menu-primary-links .expanded > a').click(function()
  {
    //$(this).parent().toggleClass('active-trail');
    $(this).next().slideToggle('slow');
    return false;
  });
  
  // fancybox
  /*if ( $('body').hasClass('section-photos') )
  {
    $('a.imagecache-photo_thumb').attr('rel','gallery').fancybox({overlayColor: '#000'});
  }*/
}