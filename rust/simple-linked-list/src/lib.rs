use std::{fmt::Debug, iter::FromIterator};

#[derive(Debug)]
struct Node<T: Debug> {
    data: T,
    next: Option<Box<Node<T>>>,
}

#[derive(Debug)]
pub struct SimpleLinkedList<T: Debug> {
    head: Option<Box<Node<T>>>,
}

impl<T: Debug> SimpleLinkedList<T> {
    pub fn new() -> Self {
        SimpleLinkedList { head: None }
    }

    pub fn is_empty(&self) -> bool {
        self.head.is_none()
    }

    pub fn len(&self) -> usize {
        let mut cur = &self.head;
        let mut len = 0;

        while let Some(node) = cur {
            len += 1;
            cur = &node.next;
        }

        len
    }

    pub fn push(&mut self, data: T) {
        self.head = Some(Box::new(Node {
            data,
            next: self.head.take(),
        }));
    }

    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            node.data
        })
    }

    pub fn peek(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.data)
    }

    #[must_use]
    pub fn rev(self) -> SimpleLinkedList<T> {
        let mut result = Self::new();
        let mut cur = self.head;

        while let Some(node) = cur {
            result.push(node.data);
            cur = node.next;
        }

        result
    }
}

impl<T: Debug> FromIterator<T> for SimpleLinkedList<T> {
    fn from_iter<I: IntoIterator<Item = T>>(iter: I) -> Self {
        let mut list = Self::new();

        for x in iter {
            list.push(x);
        }

        list
    }
}

impl<T: Debug> From<SimpleLinkedList<T>> for Vec<T> {
    fn from(linked_list: SimpleLinkedList<T>) -> Vec<T> {
        let mut result = Vec::new();
        let mut cur = linked_list.rev().head;

        while let Some(node) = cur {
            result.push(node.data);
            cur = node.next;
        }

        result
    }
}
