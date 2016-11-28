---
layout: docs
title: Flexbox grid system
description: Documentation and examples for using Bootstrap's optional flexbox grid system.
group: layout
---

Fancy a more modern grid system? [Enable flexbox support in Bootstrap]({{ site.baseurl }}/getting-started/flexbox/) to take full advantage of CSS's Flexible Box module for even more control over your site's layout, alignment, and distribution of content.

Bootstrap's flexbox grid includes support for every feature from our [default grid system]({{ site.baseurl }}/layout/grid/), and then some. Please read the [default grid system docs]({{ site.baseurl }}/layout/grid/) before proceeding through this page. Features that are covered there are only summarized here. Please note that **Internet Explorer 9 does not support flexbox**, so proceed with caution when enabling it.

{% callout warning %}
**Heads up!** This flexbox grid documentation is powered by an additional CSS file that overrides our default grid system's CSS. This is only available in our hosted docs and is disabled in development.
{% endcallout %}

## Contents

* Will be replaced with the ToC, excluding the "Contents" header
{:toc}

## How it works

The flexbox grid system behaves similar to our default grid system, but with a few notable differences:

- [Grid mixins]({{ site.baseurl }}/layout/grid#sass-mixins) and [predefined classes]({{ site.baseurl }}/layout/grid#predefined-classes) include support for flexbox. Just [enable flexbox support]({{ site.baseurl }}/getting-started/flexbox/) to utilize them as you would otherwise.
- Nesting, offsets, pushes, and pulls are all supported in the flexbox grid system.
- Flexbox grid columns without a set width will automatically layout with equal widths. For example, four columns will each automatically be 25% wide.
- Flexbox grid columns have significantly more alignment options available, including vertical alignment.
- Unlike the default grid system where a grid column starts as full-width in the `xs` tier, **flexbox requires a `.col-{breakpoint}` class for each tier.**
- Be aware of the limitations and [bugs around flexbox](https://github.com/philipwalton/flexbugs), like the [inability to use some HTML elements as flex containers](https://github.com/philipwalton/flexbugs#9-some-html-elements-cant-be-flex-containers).

Chill? Awesome—keep reading for more information and some code snippets.

## Auto-layout columns

When flexbox support is enabled, you can utilize breakpoint-specific column classes for equal-width columns. Add any number of `.col-{breakpoint}`s for each breakpoint you need and every column will be the same width.

### Equal-width

For example, here are two grid layouts that apply to every device and viewport, from `xs` to `xl`.

<div class="bd-example-row">
{% example html %}
<div class="container">
  <div class="row">
    <div class="col">
      1 of 2
    </div>
    <div class="col">
      1 of 2
    </div>
  </div>
  <div class="row">
    <div class="col">
      1 of 3
    </div>
    <div class="col">
      1 of 3
    </div>
    <div class="col">
      1 of 3
    </div>
  </div>
</div>
{% endexample %}
</div>

### Setting one column width

Auto-layout for flexbox grid columns also means you can set the width of one column and the others will automatically resize around it. You may use predefined grid classes (as shown below), grid mixins, or inline widths. Note that the other columns will resize no matter the width of the center column.

<div class="bd-example-row">
{% example html %}
<div class="container">
  <div class="row">
    <div class="col">
      1 of 3
    </div>
    <div class="col-6">
      2 of 3 (wider)
    </div>
    <div class="col">
      3 of 3
    </div>
  </div>
  <div class="row">
    <div class="col">
      1 of 3
    </div>
    <div class="col-5">
      2 of 3 (wider)
    </div>
    <div class="col">
      3 of 3
    </div>
  </div>
</div>
{% endexample %}
</div>

### Variable width content

Using the `col-{breakpoint}-auto` classes, columns can size itself based on the natural width of its content. This is super handy with single line content like inputs, numbers, etc. This, in conjunction with [horizontal alignment](#horizontal-alignment) classes, is very useful for centering layouts with uneven column sizes as viewport width changes.

<div class="bd-example-row">
{% example html %}
<div class="container">
  <div class="row flex-items-md-center">
    <div class="col col-lg-2">
      1 of 3
    </div>
    <div class="col-12 col-md-auto">
      Variable width content
    </div>
    <div class="col col-lg-2">
      3 of 3
    </div>
  </div>
  <div class="row">
    <div class="col">
      1 of 3
    </div>
    <div class="col-12 col-md-auto">
      Variable width content
    </div>
    <div class="col col-lg-2">
      3 of 3
    </div>
  </div>
</div>
{% endexample %}
</div>

## Responsive flexbox

Unlike the default grid system, the flexbox grid requires a class for full-width columns. If you have a `.col-sm-6` and don't add `.col-12`, your `xs` grid will not render correctly. Note that flexbox grid tiers still scale up across breakpoints, so if you want two 50% wide columns across `sm`, `md`, and `lg`, you only need to set `.col-sm-6`.

<div class="bd-example-row">
{% example html %}
<div class="container">
  <div class="row">
    <div class="col-12 col-sm-6">
      1 of 2 (stacked on mobile)
    </div>
    <div class="col-12 col-sm-6">
      1 of 2 (stacked on mobile)
    </div>
  </div>
</div>
{% endexample %}
</div>

## Vertical alignment

Use the flexbox alignment utilities to vertically align columns.

<div class="bd-example-row">
{% example html %}
<div class="container">
  <div class="row flex-items-top">
    <div class="col">
      One of three columns
    </div>
    <div class="col">
      One of three columns
    </div>
    <div class="col">
      One of three columns
    </div>
  </div>
  <div class="row flex-items-middle">
    <div class="col">
      One of three columns
    </div>
    <div class="col">
      One of three columns
    </div>
    <div class="col">
      One of three columns
    </div>
  </div>
  <div class="row flex-items-bottom">
    <div class="col">
      One of three columns
    </div>
    <div class="col">
      One of three columns
    </div>
    <div class="col">
      One of three columns
    </div>
  </div>
</div>
{% endexample %}
</div>

<div class="bd-example-row bd-example-row-flex-cols">
{% example html %}
<div class="container">
  <div class="row">
    <div class="col flex-top">
      One of three columns
    </div>
    <div class="col flex-middle">
      One of three columns
    </div>
    <div class="col flex-bottom">
      One of three columns
    </div>
  </div>
</div>
{% endexample %}
</div>

## Horizontal alignment

Flexbox utilities for horizontal alignment also exist for a number of layout options.

<div class="bd-example-row">
{% example html %}
<div class="container">
  <div class="row flex-items-left">
    <div class="col-4">
      One of two columns
    </div>
    <div class="col-4">
      One of two columns
    </div>
  </div>
  <div class="row flex-items-center">
    <div class="col-4">
      One of two columns
    </div>
    <div class="col-4">
      One of two columns
    </div>
  </div>
  <div class="row flex-items-right">
    <div class="col-4">
      One of two columns
    </div>
    <div class="col-4">
      One of two columns
    </div>
  </div>
  <div class="row flex-items-around">
    <div class="col-4">
      One of two columns
    </div>
    <div class="col-4">
      One of two columns
    </div>
  </div>
  <div class="row flex-items-between">
    <div class="col-4">
      One of two columns
    </div>
    <div class="col-4">
      One of two columns
    </div>
  </div>
</div>
{% endexample %}
</div>

## Reordering

Flexbox utilities for controlling the **visual order** of your content.

<div class="bd-example-row">
{% example html %}
<div class="container">
  <div class="row">
    <div class="col flex-unordered">
      First, but unordered
    </div>
    <div class="col flex-last">
      Second, but last
    </div>
    <div class="col flex-first">
      Third, but first
    </div>
  </div>
</div>
{% endexample %}
</div>
